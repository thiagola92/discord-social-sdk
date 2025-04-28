
#include "discordpp_classes.h"

using namespace godot;

void DiscordppAuthorizationArgs::Drop() {
	obj->Drop();
}

int64_t DiscordppAuthorizationArgs::ClientId() {
	return obj->ClientId();
}

void DiscordppAuthorizationArgs::SetClientId(int64_t ClientId) {
	int64_t p0 = ClientId;

	obj->SetClientId(p0);
}

String DiscordppAuthorizationArgs::Scopes() {
	return String(obj->Scopes().c_str());
}

void DiscordppAuthorizationArgs::SetScopes(String Scopes) {
	std::string p0 = std::string(Scopes.utf8().get_data());

	obj->SetScopes(p0);
}

Variant DiscordppAuthorizationArgs::State() {
	auto r = obj->State();

	if (!r.has_value()) {
		return nullptr;
	}

	return Variant(r.value().c_str());
}

void DiscordppAuthorizationArgs::SetState(Variant State) {
	std::optional<std::string> p0;

	if (State.get_type() == Variant::STRING) {
		p0 = State.stringify().utf8().get_data();
	}

	obj->SetState(p0);
}

Variant DiscordppAuthorizationArgs::Nonce() {
	auto r = obj->Nonce();

	if (!r.has_value()) {
		return nullptr;
	}

	return Variant(r.value().c_str());
}

void DiscordppAuthorizationArgs::SetNonce(Variant Nonce) {
	std::optional<std::string> p0;

	if (Nonce.get_type() == Variant::STRING) {
		p0 = Nonce.stringify().utf8().get_data();
	}

	obj->SetNonce(p0);
}

Variant DiscordppAuthorizationArgs::CodeChallenge() {
	auto r = obj->CodeChallenge();

	if (!r.has_value()) {
		return nullptr;
	}

	discordpp::AuthorizationCodeChallenge *t_r = memnew(discordpp::AuthorizationCodeChallenge(std::move(r.value())));
	return Variant(memnew(DiscordppAuthorizationCodeChallenge{ t_r }));
}

void DiscordppAuthorizationArgs::SetCodeChallenge(Variant CodeChallenge) {
	std::optional<discordpp::AuthorizationCodeChallenge> p0;

	if (CodeChallenge.get_type() == Variant::OBJECT) {
		DiscordppAuthorizationCodeChallenge *t_p0 = Object::cast_to<DiscordppAuthorizationCodeChallenge>(CodeChallenge);
		p0 = std::optional<discordpp::AuthorizationCodeChallenge>{ *t_p0->unwrap() };
	}

	obj->SetCodeChallenge(p0);
}

void DiscordppAuthorizationArgs::_bind_methods() {
	ClassDB::bind_method(D_METHOD("Drop"),
			&DiscordppAuthorizationArgs::Drop);

	ClassDB::bind_method(D_METHOD("ClientId"),
			&DiscordppAuthorizationArgs::ClientId);

	ClassDB::bind_method(D_METHOD("SetClientId", "ClientId"),
			&DiscordppAuthorizationArgs::SetClientId);

	ClassDB::bind_method(D_METHOD("Scopes"),
			&DiscordppAuthorizationArgs::Scopes);

	ClassDB::bind_method(D_METHOD("SetScopes", "Scopes"),
			&DiscordppAuthorizationArgs::SetScopes);

	ClassDB::bind_method(D_METHOD("State"),
			&DiscordppAuthorizationArgs::State);

	ClassDB::bind_method(D_METHOD("SetState", "State"),
			&DiscordppAuthorizationArgs::SetState);

	ClassDB::bind_method(D_METHOD("Nonce"),
			&DiscordppAuthorizationArgs::Nonce);

	ClassDB::bind_method(D_METHOD("SetNonce", "Nonce"),
			&DiscordppAuthorizationArgs::SetNonce);

	ClassDB::bind_method(D_METHOD("CodeChallenge"),
			&DiscordppAuthorizationArgs::CodeChallenge);

	ClassDB::bind_method(D_METHOD("SetCodeChallenge", "CodeChallenge"),
			&DiscordppAuthorizationArgs::SetCodeChallenge);
}
